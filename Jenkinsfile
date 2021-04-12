pipeline {
    agent {
        docker {
            image 'jmorenof/platformio:latest'
            args '-v /dev/bus/usb:/dev/bus/usb --device=/dev/ttyUSB0 -u 1000:1000'
        }
    }
    stages {
        stage('Test') {
            steps {
                sh 'cd ./plataformas/arduino/ && ./correr.sh'
            }
        }
    }
}