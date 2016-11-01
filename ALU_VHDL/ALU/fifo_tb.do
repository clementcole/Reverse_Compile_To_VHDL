onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /fifo_32_tb/clk
add wave -noupdate /fifo_32_tb/din
add wave -noupdate /fifo_32_tb/dout
add wave -noupdate /fifo_32_tb/empty
add wave -noupdate /fifo_32_tb/full
add wave -noupdate /fifo_32_tb/rd_en
add wave -noupdate /fifo_32_tb/rst
add wave -noupdate /fifo_32_tb/wr_en
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {20 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
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
WaveRestoreZoom {0 ns} {832 ns}
