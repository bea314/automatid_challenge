set(COMPONENT_SRCS
	"main.c"
	"wifi_handler.c"
	)

idf_component_register(SRCS "${COMPONENT_SRCS}" INCLUDE_DIRS ".")

