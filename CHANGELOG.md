
## Unreleased

### Changes for ROS2 Compatibility and Newer Dependencies

1. **Abseil Compatibility**
   - Created `src/abseil_compat.cpp` to provide compatibility shims for abseil symbol changes
   - Created `include/cartographer_ros/thread_safe_annotations.h` with empty macro definitions for thread safety annotations
   - Updated CMakeLists.txt to use linker flags (`--no-as-needed`, `--whole-archive`, `--copy-dt-needed-entries`) to ensure proper symbol resolution with newer abseil versions
   - Changed library type from SHARED to STATIC to improve symbol resolution

2. **URDF Header Compatibility**
   - Updated `src/offline_node.cpp` to use `urdf/model.hpp` instead of deprecated `urdf/model.h`
   - Updated CMakeLists.txt to conditionally use `USE_URDF_H_FILES` for older ROS distributions that still have `urdf/model.h`

3. **Executable Linking Refactor**
   - Simplified cartographer_node, cartographer_occupancy_grid_node, and cartographer_offline_node to link against the cartographer_ros library instead of directly linking all dependencies
   - This reduces symbol duplication and simplifies the build configuration

4. **Lua Configuration Files Integration** (pixi-specific)
   - Added CMake code in the install phase to create symlinks from cartographer_ros configuration directory to cartographer's lua configuration files
   - This resolves the "Is a directory" runtime error that occurred when cartographer_ros configuration files tried to include files from the cartographer package
   - The change is backward compatible and only affects isolated environments like pixi; standard installations are unaffected

### Previous Changes

1. Merged fix from https://github.com/ros2/cartographer_ros/pull/81 to resolve duplicate symbol
   error
2. Locked down dependency versions for ros2 jazzy on noble (well, using pixi).
