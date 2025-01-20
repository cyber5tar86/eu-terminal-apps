install(
    TARGETS cdc-cluster-app_exe
    RUNTIME COMPONENT cdc-cluster-app_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
