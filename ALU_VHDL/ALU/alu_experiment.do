onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /alu_experiment_32_tb/clk
add wave -noupdate /alu_experiment_32_tb/A
add wave -noupdate /alu_experiment_32_tb/B
add wave -noupdate /alu_experiment_32_tb/rst
add wave -noupdate /alu_experiment_32_tb/input_ready
add wave -noupdate /alu_experiment_32_tb/output_ready
add wave -noupdate /alu_experiment_32_tb/Operation
add wave -noupdate /alu_experiment_32_tb/Result
add wave -noupdate /alu_experiment_32_tb/Period
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {660 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 235
configure wave -valuecolwidth 134
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
WaveRestoreZoom {544 ns} {687 ns}
