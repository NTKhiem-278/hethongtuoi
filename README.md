

# HỆ THỐNG TƯỚI CÂY TỰ ĐỘNG TRIỂN KHAI TRÊN NỀN TẢNG OPENREMOTE

# Các thành viên:
Nguyễn Thiện Khiêm - 23050031
Ngô Nhật Tân – 23050018

# Hướng dẫn sử dụng:

Phần mềm cần thiết để chạy tiểu luận:

Docker Desktop.
Docker Compose.
Arduino IDE. (Để nạp code cho ESP8266).

# Bước 1: Chuẩn bị môi trường
Vào thư mục openremote_local.
Mở CMD, Git Bash, hoặc Terminal tại thư mục này.

# Bước 2: Build và chạy Docker Compose
Gõ lệnh sau để build các container, image, và volume trong Docker:
docker compose -f "docker-compose.yml" up -d --build

# Bước 3: Khôi phục dữ liệu cho các volume
docker run --rm -v docker_openremote-mqtt-broker-volume:/volume -v /d/backups:/backup alpine sh -c "tar -xzvf /backup/docker_openremotelabs-mqtt-broker-volume.tar.gz -C /volume" docker run --rm -v docker_openremote_data:/volume -v /d/backups:/backup alpine sh -c "tar -xzvf /backup/docker_openremote_data.tar.gz -C /volume", copy thư mục backups đem vào ổ d/e

# Bước 4: Build và chạy Docker Compose
Khi chạy dự án sử dụng: localhost:8080 dể có thể vào giao diện của OpenRemote để kết nối cơ sở dữ liệu: mqtt-broker của OpenRemote trong phần Data source. Tiến hành tạo dashboard để có thể show dữ liệu.
