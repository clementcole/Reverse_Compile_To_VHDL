onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /math_expression_2_tb/rst
add wave -noupdate /math_expression_2_tb/clk
add wave -noupdate /math_expression_2_tb/input_ready_0
add wave -noupdate /math_expression_2_tb/input_ready_node1
add wave -noupdate /math_expression_2_tb/A
add wave -noupdate /math_expression_2_tb/B
add wave -noupdate /math_expression_2_tb/OP1
add wave -noupdate /math_expression_2_tb/output_ready_node1
add wave -noupdate /math_expression_2_tb/input_ready_node2
add wave -noupdate /math_expression_2_tb/C
add wave -noupdate /math_expression_2_tb/D
add wave -noupdate /math_expression_2_tb/OP2
add wave -noupdate /math_expression_2_tb/output_ready_node2
add wave -noupdate /math_expression_2_tb/input_ready_node3
add wave -noupdate /math_expression_2_tb/X
add wave -noupdate /math_expression_2_tb/A_plus_B
add wave -noupdate /math_expression_2_tb/OP3
add wave -noupdate /math_expression_2_tb/output_ready_node3
add wave -noupdate /math_expression_2_tb/X_times_A_plus_B
add wave -noupdate /math_expression_2_tb/input_ready_node4
add wave -noupdate /math_expression_2_tb/Y
add wave -noupdate /math_expression_2_tb/C_plus_D
add wave -noupdate /math_expression_2_tb/OP4
add wave -noupdate /math_expression_2_tb/output_ready_node4
add wave -noupdate /math_expression_2_tb/Y_times_C_plus_D
add wave -noupdate /math_expression_2_tb/OP5
add wave -noupdate /math_expression_2_tb/input_ready_node5
add wave -noupdate /math_expression_2_tb/output_ready_5
add wave -noupdate /math_expression_2_tb/FinalResult
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {115 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 294
configure wave -valuecolwidth 182
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {90 ns} {180 ns}
