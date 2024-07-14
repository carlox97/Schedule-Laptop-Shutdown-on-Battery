# Schedule Laptop Shutdown on Battery

move schedule.c in /root/schedule.c

    wget https://github.com/carlox97/Schedule-Laptop-Shutdown-on-Battery/raw/main/schedule.c
    mv schedule.c /root/schedule.c
    gcc /root/schedule.c -o /root/schedule
    chmod +x /root/schedule

## create a CronJob (run every 5 minutes)

    crontab -e

paste 

    */5 * * * * /root/schedule >/dev/null 2>&1

save and close: CTRL + X and press Y if you use nano.
