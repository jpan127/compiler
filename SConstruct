import sys
import os
import SCons

# Set up default environment path
DefaultEnvironment(
    ENV = {
        "PATH" : os.environ["PATH"]
    },
)

#=======================================================#
#                       Constants                       #
#=======================================================#

GENERATED_DIR     = "generated"
GRAMMAR_FILE_NAME = "C"
ANLTR_STATIC_LIB  = "antlr-runtime"
ANTLR_LIB_DIR     = Dir("libs")
COMPILE           = ARGUMENTS.get("run", None)

# http://patorjk.com/software/taag/#p=display&f=Bloody&t=Antlr - Bloody Font
print("""

  ▄████ ▓█████  ███▄    █ ▓█████  ██▀███   ▄▄▄     ▄▄▄█████▓ ██▓ ███▄    █   ▄████
 ██▒ ▀█▒▓█   ▀  ██ ▀█   █ ▓█   ▀ ▓██ ▒ ██▒▒████▄   ▓  ██▒ ▓▒▓██▒ ██ ▀█   █  ██▒ ▀█▒
▒██░▄▄▄░▒███   ▓██  ▀█ ██▒▒███   ▓██ ░▄█ ▒▒██  ▀█▄ ▒ ▓██░ ▒░▒██▒▓██  ▀█ ██▒▒██░▄▄▄░
░▓█  ██▓▒▓█  ▄ ▓██▒  ▐▌██▒▒▓█  ▄ ▒██▀▀█▄  ░██▄▄▄▄██░ ▓██▓ ░ ░██░▓██▒  ▐▌██▒░▓█  ██▓
░▒▓███▀▒░▒████▒▒██░   ▓██░░▒████▒░██▓ ▒██▒ ▓█   ▓██▒ ▒██▒ ░ ░██░▒██░   ▓██░░▒▓███▀▒
 ░▒   ▒ ░░ ▒░ ░░ ▒░   ▒ ▒ ░░ ▒░ ░░ ▒▓ ░▒▓░ ▒▒   ▓▒█░ ▒ ░░   ░▓  ░ ▒░   ▒ ▒  ░▒   ▒
  ░   ░  ░ ░  ░░ ░░   ░ ▒░ ░ ░  ░  ░▒ ░ ▒░  ▒   ▒▒ ░   ░     ▒ ░░ ░░   ░ ▒░  ░   ░
░ ░   ░    ░      ░   ░ ░    ░     ░░   ░   ░   ▒    ░       ▒ ░   ░   ░ ░ ░ ░   ░
      ░    ░  ░         ░    ░  ░   ░           ░  ░         ░           ░       ░

                ▄▄▄       ███▄    █ ▄▄▄█████▓ ██▓     ██▀███
               ▒████▄     ██ ▀█   █ ▓  ██▒ ▓▒▓██▒    ▓██ ▒ ██▒
               ▒██  ▀█▄  ▓██  ▀█ ██▒▒ ▓██░ ▒░▒██░    ▓██ ░▄█ ▒
               ░██▄▄▄▄██ ▓██▒  ▐▌██▒░ ▓██▓ ░ ▒██░    ▒██▀▀█▄
                ▓█   ▓██▒▒██░   ▓██░  ▒██▒ ░ ░██████▒░██▓ ▒██▒
                ▒▒   ▓▒█░░ ▒░   ▒ ▒   ▒ ░░   ░ ▒░▓  ░░ ▒▓ ░▒▓░
                 ▒   ▒▒ ░░ ░░   ░ ▒░    ░    ░ ░ ▒  ░  ░▒ ░ ▒░
                 ░   ▒      ░   ░ ░   ░        ░ ░     ░░   ░
                     ░  ░         ░              ░  ░   ░
""")

#=======================================================#
#                   Helper Functions                    #
#=======================================================#

def get_all_subdirectories(root_dir):
    """
    Traverses and saves all subdirectories into a list
    @param root_dir : Starting directory to traverse
    @returns        : List of all directories
    """
    subdirs = []
    for root, dirs, files in os.walk(root_dir):
        subdirs += [os.path.join(root, dir) for dir in dirs]
    return subdirs

#=======================================================#
#             Project Directories and Files             #
#=======================================================#

CPPPATH = Flatten([
    GENERATED_DIR,
    "antlr4-runtime",
    get_all_subdirectories("antlr4-runtime"),
    "src",
    get_all_subdirectories("src"),
    "generated",
])

CPPPATH = [Dir(".").Dir(dir) for dir in CPPPATH]

SOURCE_DIRS = Flatten([
    "src",
    get_all_subdirectories("src"),
])

# Glob all source files from the source directories
SOURCE_FILES = [Dir(dir).glob("*.cpp") for dir in SOURCE_DIRS]

#=======================================================#
#                   Main Environment                    #
#=======================================================#

env = Environment(
    tools      = ["mingw", "g++"],
    ENV        = os.environ,
    CPPPATH    = CPPPATH,
    LINKFLAGS  = ["-static-libstdc++"],
    CXXCOMSTR  = "[Compiling $TARGET]",
    LINKCOMSTR = "[Linking $TARGET]",
    CXXFLAGS   = [
        "-std=c++11",
        "-g",
        "-Wall",
        "-Wno-trigraphs",
    ],
)

SConscript(
    "SConscript.py",
    variant_dir = "build",
    duplicate   = 0,
    exports     = [
        "env",
        "GENERATED_DIR",
        "GRAMMAR_FILE_NAME",
        "ANLTR_STATIC_LIB",
        "SOURCE_FILES",
        "ANTLR_LIB_DIR",
        "COMPILE",
    ],
)
