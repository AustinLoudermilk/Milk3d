workspace "Milk"
    architecture "x64"

    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Milk/vendor/GLFW/include"
IncludeDir["Glad"] = "Milk/vendor/Glad/include"
IncludeDir["ImGui"] = "Milk/vendor/imgui"

include "Milk/vendor/GLFW"
include "Milk/vendor/Glad"
include "Milk/vendor/imgui"

project "Milk"
    location "Milk"
    kind "SharedLib"
    language "C++"

    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mkpch.h"
    pchsource "Milk/src/mkpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "MK_PLATFORM_WINDOWS",
            "MK_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "MK_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "MK_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "MK_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Milk/vendor/spdlog/include",
        "Milk/src"
    }

    links
    {
        "Milk"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "MK_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "MK_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "MK_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "MK_DIST"
        runtime "Release"
        optimize "On"