#!/bin/bash
# Build and install PrismModern on Arch Linux
set -e

echo "=== PrismModern Build Script ==="
echo ""

# Check dependencies
echo "Checking dependencies..."
for cmd in cmake g++ make; do
    if ! command -v $cmd &>/dev/null; then
        echo "ERROR: $cmd is required but not installed"
        exit 1
    fi
done

# Check for Qt6
if ! qmake-qt6 --version &>/dev/null 2>&1; then
    echo "ERROR: Qt6 development tools not found"
    echo "Install with: sudo pacman -S qt6-base qt6-declarative"
    exit 1
fi

QMAKE_VERSION=$(qmake-qt6 --version | head -1)
echo "Qt6 found: $QMAKE_VERSION"

# Install system dependencies
echo ""
echo "Installing system dependencies..."
sudo pacman -S --needed --noconfirm \
    qt6-base \
    qt6-declarative \
    qt6-tools \
    cmake \
    g++ \
    make

# Build the project
echo ""
echo "=== Building PrismModern ==="
cd "$(dirname "$0")"

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

# Run cmake
echo "Running cmake configuration..."
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr

# Build
echo "Building..."
make -j$(nproc)

# Install
echo "Installing..."
sudo make install

echo ""
echo "=== PrismModern installed successfully! ==="
echo ""
echo "You can launch it with:"
echo "  prismmodern"
echo "  # Or from the application menu"
echo ""
echo "Enjoy your modern Minecraft-inspired launcher! ✨"