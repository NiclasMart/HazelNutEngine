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

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "HazelNut/vendor/GLFW/include"
IncludeDir["Glad"] = "HazelNut/vendor/Glad/include"
IncludeDir["ImGui"] = "HazelNut/vendor/imgui"

group "Dependencies"
	include "HazelNut/vendor/GLFW"
	include "HazelNut/vendor/Glad"
	include "HazelNut/vendor/imgui"
group ""

project "HazelNut"
	location "HazelNut"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
			"HZN_PLATFORM_WINDOWS",
			"HZN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "HZN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HZN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HZN_DIST"
		runtime "Release"
		optimize "On"

	ignoredefaultlibraries {
		"libcmtd"
	}


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
		"HazelNut/src",
		"HazelNut/vendor/spdlog/include"
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
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HZN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HZN_DIST"
		runtime "Release"
		optimize "On"



