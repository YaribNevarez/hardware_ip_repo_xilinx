# Zybo xdc for PMOD ADCs and DACs

############################
# On-board leds            #
############################
##IO_L23P_T3_35
set_property PACKAGE_PIN M14 [get_ports e_out_vector_0[0]]
set_property IOSTANDARD LVCMOS33 [get_ports e_out_vector_0[0]]

##IO_L23N_T3_35
set_property PACKAGE_PIN M15 [get_ports e_out_vector_0[1]]
set_property IOSTANDARD LVCMOS33 [get_ports e_out_vector_0[1]]

##IO_0_35
set_property PACKAGE_PIN G14 [get_ports e_out_vector_0[2]]
set_property IOSTANDARD LVCMOS33 [get_ports e_out_vector_0[2]]

##IO_L3N_T0_DQS_AD1N_35
set_property PACKAGE_PIN D18 [get_ports e_out_vector_0[3]]
set_property IOSTANDARD LVCMOS33 [get_ports e_out_vector_0[3]]

############################
# On-board switches        #
############################
##IO_L19N_T3_VREF_35
set_property PACKAGE_PIN G15 [get_ports e_in_vector_0[0]]
set_property IOSTANDARD LVCMOS33 [get_ports e_in_vector_0[0]]

##IO_L24P_T3_34
set_property PACKAGE_PIN P15 [get_ports e_in_vector_0[1]]
set_property IOSTANDARD LVCMOS33 [get_ports e_in_vector_0[1]]

##IO_L4N_T0_34
set_property PACKAGE_PIN W13 [get_ports e_in_vector_0[2]]
set_property IOSTANDARD LVCMOS33 [get_ports e_in_vector_0[2]]

##IO_L9P_T1_DQS_34
set_property PACKAGE_PIN T16 [get_ports e_in_vector_0[3]]
set_property IOSTANDARD LVCMOS33 [get_ports e_in_vector_0[3]]

#############################
## On-board pushbuttons     #
#############################
###IO_L20N_T3_34
#set_property PACKAGE_PIN R18 [get_ports zPushB[0]]
#set_property IOSTANDARD LVCMOS33 [get_ports zPushB[0]]

###IO_L24N_T3_34
#set_property PACKAGE_PIN P16 [get_ports zPushB[1]]
#set_property IOSTANDARD LVCMOS33 [get_ports zPushB[1]]

###IO_L18P_T2_34
#set_property PACKAGE_PIN V16 [get_ports zPushB[2]]
#set_property IOSTANDARD LVCMOS33 [get_ports zPushB[2]]

###IO_L7P_T1_34
#set_property PACKAGE_PIN Y16 [get_ports zPushB[3]]
#set_property IOSTANDARD LVCMOS33 [get_ports zPushB[3]]

