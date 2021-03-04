#powershell.exe .\build.ps1
#powershell.exe .\build.ps1 -config
#powershell.exe .\build.ps1 -release
#powershell.exe .\build.ps1 -release -config

param (
    [switch]$release = $false,
    [switch]$config = $false,
    [switch]$unity = $false
)

[string]$build_folder = "debug"
[string]$cmake_build = "Debug"
if($release){
    $build_folder = "release"
    $cmake_build = "RelWithDebInfo"
}
[string]$builds = "${PSScriptRoot}\builds\${build_folder}_msvc_ninja"

[string]$unity_str = ""
if($unity){
    $unity_str = "-DCMAKE_UNITY_BUILD=ON -CMAKE_UNITY_BUILD_BATCH_SIZE=0"
}

if($config){    
    Remove-Item $builds -Force -Recurse -ErrorAction SilentlyContinue
    New-Item -Path $builds -ItemType Directory
    Push-Location -Path $builds    
    iex "cmake -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl -DCMAKE_BUILD_TYPE=${cmake_build} ${unity_str} -G `"Ninja`" ../../"
    Pop-Location
}

Push-Location -Path $builds
iex "cmake.exe --build ."
iex ".\RTIOW_C.exe 3 2 test.tga"
iex "& 'C:\Program Files\GIMP 2\bin\gimp-2.10.exe' 'test.tga'"
Pop-Location
