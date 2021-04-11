pipeline {
    agent {
        docker { image 'jmorenof/platformio:latest' }
    }
    stages {
        stage('Test') {
            steps {
                sh 'platformio test -e esp32dev'
            }
        }
    }
}