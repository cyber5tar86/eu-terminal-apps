FROM ubuntu:24.10

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential \
    clang \
    cmake \
    freeglut3-dev \
    gdb \
    git \
    libdbus-1-3 \
    libdbus-1-dev \
    libegl1 \
    libgl-dev \
    libgl1-mesa-dev \
    libgles2-mesa-dev \
    libglew-dev \
    libglfw3-dev \
    libglib2.0-0 \
    libglib2.0-dev \
    libglm-dev \
    libglu1-mesa-dev \
    libqt6networkauth6-dev \
    libqt6sensors6-dev \
    libqt6serialbus6-dev \
    libqt6serialport6-dev \
    libqt6shadertools6-dev \
    libqt6svg6-dev \
    libqt6virtualkeyboard6-dev \
    libqt6webchannel6-dev \
    libqt6websockets6-dev \
    libssl-dev \
    libvulkan-dev \
    libxcb-cursor0 \
    libxcb-icccm4 \
    libxcb-keysyms1 \
    libxcb-shape0 \
    libxcb-xkb1 \
    libxkbcommon-dev \
    libxkbcommon-dev \
    libxkbcommon-x11-0 \
    libxkbcommon-x11-dev \
    lld \
    locales \
    mesa-common-dev \
    mesa-utils \
    ninja-build \
    python3 \
    python3-pip \
    python3-sphinx \
    python3-venv \
    qt6-3d-dev \
    qt6-base-dev \
    qt6-base-private-dev \
    qt6-charts-dev \
    qt6-connectivity-dev \
    qt6-datavisualization-dev \
    qt6-declarative-dev \
    qt6-l10n-tools \
    qt6-multimedia-dev \
    qt6-pdf-dev \
    qt6-positioning-dev \
    qt6-quick3d-dev \
    qt6-remoteobjects-dev \
    qt6-scxml-dev \
    qt6-shader-baker qt6-tools-dev qt6-wayland-dev \
    qt6-wayland-dev-tools \
    qt6-webengine-dev \
    qt6-webengine-dev-tools \
    qt6-webview-dev \
    ranger \
    spirv-tools \
    sudo \
    sudo \
    unzip \
    wget \
    xvfb && \
    rm -rf /var/lib/apt/lists/*


RUN touch /var/mail/ubuntu && \
    chown ubuntu /var/mail/ubuntu && \
    userdel -r ubuntu

ARG USER_ID=1000
ARG GROUP_ID=1000

RUN groupadd -g ${GROUP_ID} user && \
    useradd -ms /bin/bash -u ${USER_ID} -g user user -G sudo && \
    echo "user ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

RUN echo "root:root" | chpasswd
RUN echo "user:root" | chpasswd

USER user

WORKDIR /home/user

RUN pip install --break-system-packages --user pipx && \
    ${HOME}/.local/bin/pipx ensurepath && \
    ${HOME}/.local/bin/pipx completions && \
    eval "$(register-python-argcomplete pipx)"

RUN ${HOME}/.local/bin/pipx install conan