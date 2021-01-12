workspace "Maze"
	architecture "x64"
	startproject "Maze"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

project "Maze"
	location ""
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir  ("bin/" .. outputdir  .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir  .. "/%{prj.name}")

	files 
	{
		"src/**.h",
		"src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.magick}",
	}

	links 
	{		

	}
	
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"RBL_PLATFORM_WINDOWS",
			"RBL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "RBL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RBL_RELEASE"
		runtime "Release"
		symbols "on"

	filter "configurations:Dist"
		defines "RBL_DIST"
		runtime "Release"
		symbols "on"

	filter { "system:windows", "configurations:Release" }
        buildoptions "/MTd"