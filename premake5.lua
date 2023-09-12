workspace "Kami"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kami"
	location "Kami"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kmpch.h"
	pchsource "Kami/src/kmpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"KM_PLATFORM_WINDOWS",
			"KM_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter  "configurations:Debug"
		defines "KM_DEBUG"
		symbols "On"
	
	filter  "configurations:Release"
		defines "KM_RELEASE"
		optimize "On"	

	filter  "configurations:Dist"
		defines "KM_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Kami/vendor/spdlog/include",
		"Kami/src"
	}

	links {
		"Kami"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"KM_PLATFORM_WINDOWS",
		}

	filter  "configurations:Debug"
		defines "KM_DEBUG"
		symbols "On"
	
	filter  "configurations:Release"
		defines "KM_RELEASE"
		optimize "On"	

	filter  "configurations:Dist"
		defines "KM_DIST"
		optimize "On"