# Zeit project
 Qt frontend to `crontab` and `at`

### Features: ###
* Add, edit and delete `crontab` tasks
* Add, edit and delete environment variables for `crontab`
* Add and delete `at` commands
* Alarms and Timers

### Build and run ###
```bash
mkdir build && cd build
cmake ..
make -j2
./src/zeit
```

### Screenshot ###
![Screenshot of the Zeit app](https://lh3.googleusercontent.com/-Ju_EuEcBNcY/V63bFFcrWJI/AAAAAAAAAiQ/Uz0SAuiMpTgs0ncY5B988chnFboTqRgpQCL0B/s0/zeit.png)

### Installation on Ubuntu ###
```
sudo add-apt-repository ppa:blaze/main
sudo apt update
sudo apt install zeit
```
