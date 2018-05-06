Import("*")



#=======================================================#
#                    Compile Sources                    #
#=======================================================#

bash_script_arguments = {
    "GRAMMAR" : "Pcl2.g4",
    "TARGET"  : "Cpp",
    "SAMPLE"  : "sample.pas",
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

SOURCE_FILES += Dir(GENERATED_DIR).glob("*.cpp")

compilation = env.Program(
    target = "compiler",
    source = Flatten(SOURCE_FILES),
    variant_dir=".",
    LIBS = [
        "antlr-runtime2",
    ],
    LIBPATH = [
        ".",
        ANTLR_DLL_DIR,
    ],
)

Depends(compilation, autogenerate_antlr)
