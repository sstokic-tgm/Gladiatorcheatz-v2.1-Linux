# output generic information about the core and buildtype chosen
message("")
message("* Gladiatorcheatz revision   : ${rev_hash} ${rev_date} (${rev_branch} branch)")
if(UNIX)
    message("* Gladiatorcheatz buildtype  : ${CMAKE_BUILD_TYPE}")
endif()

if(WITHOUT_GIT)
    message("* Use GIT revision hash  : No")
else()
    message("* Use GIT revision hash  : Yes (default)")
endif()

message("")