set(COMPONENT_SRCS
	"main.c"
	"wifi_handler.c"
	"mqtt_main.c"
	"mqtt_helpers.c"
	)

idf_component_register(SRCS "${COMPONENT_SRCS}" INCLUDE_DIRS ".")

