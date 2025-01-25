FROM php:8.0-apache

# Salin folder app ke dalam direktori root Apache
COPY app/ /var/www/html/

# Ubah izin file agar dapat diakses
RUN chmod -R 755 /var/www/html/

# Expose port 80
EXPOSE 80
