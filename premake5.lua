workspace "Gluten"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Gluten/vendor/GLFW/include"
IncludeDir["Glad"] = "Gluten/vendor/Glad/include"
IncludeDir["ImGui"] = "Gluten/vendor/imgui"


include "Gluten/vendor/GLFW"
include "Gluten/vendor/Glad"
include "Gluten/vendor/imgui"


project "Gluten"
	location "Gluten"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "glutpch.h"
	pchsource "Gluten/src/glutpch.cpp"

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
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLUT_PLATFORM_WINDOWS",
			"GLUT_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GLUT_DEBUG"
        buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GLUT_RELEASE"
        buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "GLUT_DIST"
        buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Gluten/vendor/spdlog/include",
		"Gluten/src"
	}

	links
	{
		"Gluten"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLUT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GLUT_DEBUG"
        buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GLUT_RELEASE"
        buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "GLUT_DIST"
        buildoptions "/MD"
		optimize "On"