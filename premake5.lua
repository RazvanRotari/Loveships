



workspace "LoveShips"
   configurations { "Debug", "Release" }

project "LoveShips"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "src/**.hpp", "src/**.cpp" }

   libdirs { "3rdparty/entityx" }
   links {"entityx", "sfml-system", "sfml-window", "sfml-graphics", "sfml-audio", "boost_system", "boost_filesystem"}

   buildoptions {"-std=c++14"}
   warnings "Extra"

   filter "configurations:Debug"
   --  ugly hack to use clang

        defines { "DEBUG" }
        flags { "Symbols" }

   filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
