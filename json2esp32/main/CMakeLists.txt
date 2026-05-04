idf_component_register(SRCS "json2esp32.cpp"
                    "drivers/uda1334a/uda1334a.cpp"
                    INCLUDE_DIRS "." "drivers/uda1334a"
                    REQUIRES driver)
