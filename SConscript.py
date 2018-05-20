Import("*")
import os


#=======================================================#
#                    Compile Sources                    #
#=======================================================#

bash_script_arguments = {
    "SCRIPT"  : "scripts/build.sh",
    "GRAMMAR" : "Cmm.g4",
    "TARGET"  : "Cpp",
    "FILE"    : "{}.c".format(COMPILE),
}

autogenerate_antlr = env.Command(
    target = "autogenerate_antlr",
    source = [],
    action = env.Action(
        "bash {SCRIPT} -g {GRAMMAR} -t {TARGET} -f {FILE}".format(**bash_script_arguments),
        "Calling {} to autogenerate antlr code...".format(bash_script_arguments["SCRIPT"]),
    ),
)

AlwaysBuild(autogenerate_antlr)

SOURCE_FILES += Dir(GENERATED_DIR).glob("*.cpp")
SOURCE_FILES = Flatten(SOURCE_FILES)

object_files = []
for cpp in SOURCE_FILES:
    object_files.append(
        env.Object(
            target  = os.path.splitext(cpp.name)[0],
            source  = cpp,
            LIBS    = [ANLTR_STATIC_LIB],
            LIBPATH = [ANTLR_LIB_DIR],
        )
    )

Depends(object_files, autogenerate_antlr)

link_exe = env.Program(
    target  = "compiler",
    source  = object_files,
    LIBS    = [ANLTR_STATIC_LIB],
    LIBPATH = [ANTLR_LIB_DIR],
)

Default(link_exe)
Depends(link_exe, autogenerate_antlr)

if COMPILE is not None:
    execute = env.Command(
        target = "execute",
        source = [link_exe],
        action = "build\compiler samples/{}.c".format(COMPILE),
    )

    Default(execute)
    AlwaysBuild(execute)