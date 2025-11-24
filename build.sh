set -e


# Get the compile-mode.
MODE=""
while getopts "m:h" opt; do
case $opt in
    m)
        MODE=$OPTARG
        if [[ "$MODE" == "debug" ]]; then
            FLAGS="-g -O0 -fsanitize=address -fno-inline -fno-omit-frame-pointer"
        elif [[ "$MODE" == "release" ]]; then
            FLAGS="-O3 -DNDEBUG -flto -fomit-frame-pointer -funroll-loops"
        elif [[ "$MODE" == "clean" ]]; then
            rm -rf "$PWD/bin"
            rm -f "$PWD/.clangd"
            exit 0
        else
            echo "Unknown MODE: $MODE"
            exit 1
        fi
        ;;
    h)
        echo "Usage: $0 -m {debug|release}"
        echo "  -m mode   Required. Must be 'debug' or 'release'"
        echo "  -h        Show this help message"
        exit 1
        ;;
    \?)
        echo "Invalid option: -$OPTARG" >&2
        exit 1
        ;;
    :)
        echo "Option -$OPTARG requires an argument." >&2
        exit 1
        ;;
    esac
done
if [[ $MODE == "" ]]; then
    echo "No mode specified."
    exit 1
fi


# Set output colors.
COLOR_STEP="\033[32m"
COLOR_SUBSTEP="\033[34m"
COLOR_COMPLETE="\033[33m"
COLOR_RESET="\033[0m"

# Set project directories.
PATH_PWD="$PWD"
PATH_SRC="$PATH_PWD/src"
PATH_INC="$PATH_PWD/inc"
PATH_BIN="$PATH_PWD/bin"
PATH_OBJ="$PATH_BIN/obj"
PATH_EXE="$PATH_BIN/$MODE.exe"

# Rebuild and enter the build directory.
rm -rf $PATH_OBJ
rm -f $PATH_EXE
mkdir -p $PATH_OBJ

cat <<EOF > ${PATH_PWD}/.clangd
CompileFlags:
    Add:
        - -std=c++23
        - -I${PATH_INC}
        - -Weverything
        - -Wno-padded
        - -Wno-c++98-compat
        - -Wno-exit-time-destructors
        - -Wno-global-constructors
        - -Wno-unused-macros
        - -Wno-newline-eof
        - -Wno-unsafe-buffer-usage
        - -Wno-pre-c++20-compat-pedantic
EOF

cd $PATH_BIN

# # Gather all .ixx files and compile each one into it's corresponding .o file in obj/.
# echo -e "${COLOR_STEP}Building module objects...${COLOR_RESET}"
# PATHS_IXX=$(find "$PATH_INC" -type f -name "*.ixx")

# for PATH_INC_IXX in $PATHS_IXX; do
#     PATH_REL_IXX="${PATH_INC_IXX#$PATH_INC}"
#     PATH_OBJ_O="$PATH_OBJ${PATH_REL_IXX%.ixx}.o"
#     PATH_SUB_OBJ="${PATH_OBJ_O%/*}"

#     mkdir -p "$PATH_SUB_OBJ"

#     echo -e "${COLOR_SUBSTEP}Compiling: $PATH_REL_IXX${COLOR_RESET}"
#     g++ -std=c++23 -fmodules $FLAGS -c "$PATH_INC_IXX" -o "$PATH_OBJ_O"
# done

# Gather all .cpp files and compile each one into it's corresponding .o file in obj/.
echo -e "${COLOR_STEP}Building c++ objects...${COLOR_RESET}"
PATHS_CPP=$(find "$PATH_SRC" -type f -name "*.cpp")

for PATH_SRC_CPP in $PATHS_CPP; do
    PATH_REL_CPP="${PATH_SRC_CPP#$PATH_SRC}"
    PATH_OBJ_O="$PATH_OBJ${PATH_REL_CPP%.cpp}.o"
    PATH_SUB_OBJ="${PATH_OBJ_O%/*}"

    mkdir -p "$PATH_SUB_OBJ"

    echo -e "${COLOR_SUBSTEP}Compiling: $PATH_REL_CPP${COLOR_RESET}"
    g++ -std=c++23 -fmodules $FLAGS -I$PATH_INC -c "$PATH_SRC_CPP" -o "$PATH_OBJ_O"
done

# Gather all object files and link the project.
echo -e "${COLOR_STEP}Linking object files...${COLOR_RESET}"
PATHS_OBJ=$(find "$PATH_OBJ" -type f -name "*.o")
g++ -std=c++23 -lxcb -lxcb-keysyms -lxkbcommon -lxkbcommon-x11 -lX11 -lX11-xcb -lGL $FLAGS $PATHS_OBJ -o $PATH_EXE

# Run the project.
echo -e "${COLOR_COMPLETE}Running compiled $MODE build ->${COLOR_RESET}"
${PATH_EXE}