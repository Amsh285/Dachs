workspace "Dachs"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Dachs/vendor/GLFW/include"

include "Dachs/vendor/GLFW"

project "Dachs"
	location "Dachs"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dspch.h"
	pchsource "Dachs/src/dspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DS_PLATFORM_WINDOWS",
			"DS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DS_DIST"
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
		"Dachs/vendor/spdlog/include",
		"Dachs/src"
	}

	links
	{
		"Dachs"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DS_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "DS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DS_DIST"
		optimize "On"
