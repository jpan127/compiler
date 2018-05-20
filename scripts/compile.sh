set -x

REPO_PATH="C:/Users/JP/Desktop/compiler"

# Call compiler from output folder so output files will be placed there
cd $REPO_PATH/outputs
../build/compiler.exe ../samples/$1.c