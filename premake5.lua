workspace "HazelNut"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HazelNut"
	location "HazelNut"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzn_pch.h"
	pchsource "HazelNut/src/hzn_pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HZN_PLATFORM_WINDOWS",
			"HZN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HZN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZN_DIST"
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
		"HazelNut/vendor/spdlog/include",
		"HazelNut/src"
	}

	links
	{
		"HazelNut"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HZN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HZN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZN_DIST"
		optimize "On"



