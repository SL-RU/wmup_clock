(ede-cpp-root-project "awaker"
                      :name "awaker"
		      :spp-table '(("__weak" . "__attribute__((weak))")
				    ("__packed" . "__attribute__((__packed__))")
				    ("USE_HAL_DRIVER" . "")
				    ("STM32F103xB" . ""))
      		      :compile-command "make"
                      :file "/home/lyra/b/wmup_clock/awaker/project.el"
                      :include-path '("/hd44780"
                                      "/sys"
                                      "/Drivers/CMSIS/Device/ST/STM32F1xx/Include"
                                      "/Drivers/CMSIS/Include"
                                      "/Drivers/STM32F1xx_HAL_Driver/Inc"
                                      "/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy"
                                      "/Inc"
                                      "/app"
                                      )
		      )