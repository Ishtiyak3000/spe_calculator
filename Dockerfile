# FROM ubuntu:latest
# RUN apt-get update && apt-get install -y g++ cmake libgtest-dev

# WORKDIR /app
# COPY . .

# RUN cmake .
# RUN make
# CMD ["./calculator"]
FROM ubuntu:latest

# Set non-interactive mode for APT to avoid prompts
ARG DEBIAN_FRONTEND=noninteractive

# Use system-installed dependencies instead of reinstalling
RUN apt-get update && apt-get install -y g++

WORKDIR /app
COPY . .

# Use the system's CMake and Google Test instead of reinstalling
RUN cmake . && make

CMD ["./calculator"]
