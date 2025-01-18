from conan import ConanFile


class Recipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps", "VirtualRunEnv"

    def layout(self):
        self.folders.generators = "build/conan"

    #def requirements(self):
        #self.requires("qt/6.7.3")

    def build_requirements(self):
        self.test_requires("gtest/1.8.1")
