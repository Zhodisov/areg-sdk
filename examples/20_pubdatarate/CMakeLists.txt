# Project names
macro_declare_project(20_generated    "generated")
macro_declare_project(20_pubclient    "pubclient")
macro_declare_project(20_pubservice   "pubservice")

# Setting up appropriate flags
addStaticLib(${project_generated}     "${generated_src}")
addExecutableEx(${project_pubclient}  "${pubclient_src}"  "${project_generated}")
addExecutableEx(${project_pubservice} "${pubservice_src}" "${project_generated}")
