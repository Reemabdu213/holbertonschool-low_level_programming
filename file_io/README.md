# 0x15. C - File I/O

مشروع التعامل مع ملفات النظام في لغة C:
- دوال open/close/read/write
- صلاحيات الملفات وfile descriptors
- التعامل مع الأخطاء (errno / perror)

## Build
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c


cd ~/holbertonschool-low_level_programming
mkdir -p file_io
cd file_io

cat > README.md << 'EOF'
# 0x15. C - File I/O
