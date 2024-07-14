# Schedule Laptop Shutdown on Battery



    sudo apt install acpi
    wget https://github.com/carlox97/Schedule-Laptop-Shutdown-on-Battery/raw/main/schedule.c
    sudo mv schedule.c /root/schedule.c
    sudo gcc /root/schedule.c -o /root/schedule
    sudo chmod +x /root/schedule

## create a CronJob (run every 5 minutes)

    sudo crontab -e

paste 

    */5 * * * * /root/schedule >/dev/null 2>&1

save and close: CTRL + X and press Y if you use nano.
