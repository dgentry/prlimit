#!/bin/bash


# ANSI escape sequence for white text
WHITE='\033[97m'
# ANSI escape sequence to reset text color
RESET='\033[0m'

# Function to print white text
msg() {
  echo -e "${WHITE}$*${RESET}"
}



# Create a temporary file to capture the output
output_file=$(mktemp)

# Run the C program in the background, capture and print the output
msg "Launching consumer"
time ./consumer &

while [[ -z $pid ]]; do
    pid=$(cat consumer_pid.txt)
    # Print the PID
    msg "PID of the CPU consumer program: $pid"
    sleep 1
done

msg "Setting CPU limit to 5 seconds"
echo -e $WHITE
./prlimit $pid 5 5
echo -e $RESET

# Not strictly necessary, but it's slightly weird to get the prompt in
# the middle of consumer's output
echo "Sleeping 6 more seconds"
sleep 6

# Clean up temporary file
rm "$output_file"
