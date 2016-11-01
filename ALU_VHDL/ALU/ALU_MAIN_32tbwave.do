onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /alu_32_tb/reset
add wave -noupdate /alu_32_tb/clk
add wave -noupdate /alu_32_tb/A
add wave -noupdate /alu_32_tb/B
add wave -noupdate /alu_32_tb/Operation
add wave -noupdate /alu_32_tb/Result
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1890000 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 139
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
configure wave -timelineunits ps
update
WaveRestoreZoom {1009389091 ps} {1009390048 ps}
