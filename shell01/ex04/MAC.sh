#!/bin/bash
ifconfig | grep ether | grep -Eo "([a-zA-Z0-9]{2}[:-]){5}([a-zA-Z0-9]{2})"
