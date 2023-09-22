import os
import subprocess


def build_and_test(directory):
    build_dir = os.path.join(directory, "build")
    if not os.path.exists(build_dir):
        print(f"Skipping '{directory}' - 'build' folder does not exist.")
        return

    os.chdir(build_dir)
    make_result = subprocess.run(
        ["make"], stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    if make_result.returncode != 0:
        print(f"Error building '{directory}':")
        print(make_result.stderr.decode())
        return

    ctest_result = subprocess.run(
        ["ctest"], stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    if ctest_result.returncode != 0:
        print(f"Tests failed in '{directory}':")
        print(ctest_result.stdout.decode())
        print(ctest_result.stderr.decode())
    else:
        print(f"Tests passed in '{directory}'.")


root_directory = os.getcwd()
subdirectories = [
    d
    for d in os.listdir(root_directory)
    if os.path.isdir(os.path.join(root_directory, d))
]
for directory in subdirectories:
    build_and_test(os.path.join(root_directory, directory))
