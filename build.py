#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import shutil


def get_cmake_path():
    root_path = os.environ["ANDROID_HOME"] + "/cmake/"
    cmake_version = [
        "3.10.2.4988404",
        "3.6.4111459",
        "3.6.3155560",
    ]
    version_path = ""
    for version in cmake_version:
        version_path = root_path + version
        if os.path.exists(version_path):
            break
    else:
        raise RuntimeError("no cmake")
    return version_path + "/bin/cmake"


def run_command(cmd):
    print(cmd)
    return os.system(cmd)


def build():
    build_dir = "build/armeabi-v7a"
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    os.makedirs(build_dir)
    os.chdir(build_dir)
    cmake_path = get_cmake_path()
    cmake_command = "{} -DCMAKE_TOOLCHAIN_FILE={}/build/cmake/android.toolchain.cmake -DANDROID_ABI={} -DANDROID_STL=c++_static ../../".format(
        cmake_path,
        os.environ["ANDROID_NDK_HOME"],
        "armeabi-v7a")
    ret = run_command(cmake_command)
    if ret != 0:
        raise RuntimeError("cmake error")
    ret = run_command("make")


def main():
    build()


if __name__ == "__main__":
    main()

