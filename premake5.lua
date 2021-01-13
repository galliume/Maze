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
IncludeDir["magick"] = "vendor/Magick++/include"


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
		"%{IncludeDir.magick}"
	}


	libdirs
	{
		"vendor/Magick++/lib"
	}

	links 
	{	
		"vendor/Magick++/lib/CORE_RL_Magick++_.lib"
	}
	
	filter "system:windows"
		systemversion "latest"

  postbuildcommands
	{
		("{COPY} vendor/Magick++/*.dll bin/" .. outputdir .. "/Maze")
	}
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		symbols "on"

	filter "configurations:Dist"
		runtime "Release"
		symbols "on"

	filter { "system:windows", "configurations:Release" }
        buildoptions "/MD"