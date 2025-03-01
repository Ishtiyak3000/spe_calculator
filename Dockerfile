# FROM ubuntu:latest
# RUN apt-get update && apt-get install -y g++ cmake libgtest-dev

# WORKDIR /app
# COPY . .

# RUN cmake .
# RUN make
# CMD ["./calculator"]
# FROM ubuntu:latest

# # Set non-interactive mode for APT to avoid prompts
# ARG DEBIAN_FRONTEND=noninteractive

# # Use system-installed dependencies instead of reinstalling
# RUN apt-get update && apt-get install -y g++

# WORKDIR /app
# COPY . .

# # Use the system's CMake and Google Test instead of reinstalling
# RUN cmake . && make

# CMD ["./calculator"]
# FROM ubuntu:latest

# # Set non-interactive mode for apt-get
# ARG DEBIAN_FRONTEND=noninteractive

# # Install necessary build tools
# RUN apt-get update && apt-get install -y \
#     g++ \
#     cmake \
#     libgtest-dev 

# WORKDIR /app
# COPY . .

# # Build the project
# RUN cmake . && make

# CMD ["./calculator"]
FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

# Install necessary tools
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libgtest-dev 

WORKDIR /app
COPY . .

# Ensure a clean build by removing old CMake cache
RUN rm -rf CMakeCache.txt CMakeFiles/

# Build the project
RUN cmake . && make

CMD ["./calculator"]


