# Schedule Laptop Shutdown on Battery

    wget https://github.com/carlox97/Schedule-Laptop-Shutdown-on-Battery/raw/main/schedule.c
    mv schedule.c /root/schedule.c
    gcc /root/schedule.c -o /root/schedule
    chmod +x /root/schedule

## create a CronJob (run every 5 minutes)

    sudo nano /etc/systemd/system/schedule.service

Paste & Save

    [Unit]
    Description=Run schedule executable
    
    [Service]
    ExecStart=/root/schedule


Then

    sudo crontab -e

Paste & Save

    */5 * * * * /bin/systemctl start schedule.service
