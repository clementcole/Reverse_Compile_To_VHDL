#!/usr/local/bin/perl -i

while (<>){
	s/\012\015//;
	print $_ . "\n";
}