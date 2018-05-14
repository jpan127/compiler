Import("*")



#=======================================================#
#                    Compile Sources                    #
#=======================================================#

bash_script_arguments = {
    "GRAMMAR" : "C.g4",
    "TARGET"  : "Cpp",
    "SAMPLE"  : "sample_program.c",
    "SCRIPT"  : "scripts/build.sh",
}

autogenerate_antlr = env.Command(
    target = "autogenerate_antlr",
    source = [],
    action = env.Action(
        "bash {0} -g {1} -t {2} -f {3}".format(bash_script_arguments["SCRIPT"],
                                               bash_script_arguments["GRAMMAR"],
                                               bash_script_arguments["TARGET"],
                                               bash_script_arguments["SAMPLE"]),
        "Calling {} to autogenerate antlr code...".format(bash_script_arguments["SCRIPT"]),
    ),
)

# @TODO : When grammar is finalized, make it into a static library
# generated_antlr = env.StaticLibrary(
#     target   = "{}".format(GENERATED_STATIC_LIB),
#     source   = [Dir(GENERATED_DIR).glob("*.cpp")],
#     CXXFLAGS = env["CXXFLAGS"] + ["-w", "-fPIC"],            # Disable warnings, nothing we can do
# )
# Depends(generated_antlr, autogenerate_antlr)

SOURCE_FILES += Dir(GENERATED_DIR).glob("*.cpp")

compilation = env.Program(
    target = "compiler",
    source = SOURCE_FILES,
    LIBS = [
        # GENERATED_STATIC_LIB,
        "antlr-runtime",
    ],
    LIBPATH = [
        ".",
        ANTLR_DLL_DIR,
    ],
)

Depends(compilation, autogenerate_antlr)
