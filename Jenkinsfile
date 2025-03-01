pipeline {
    agent any

    environment {
        DOCKERHUB_USER = credentials('DockerHubCred')
    }

    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/ishtiyak3000/spe_calculator.git'
            }
        }

        stage('Build') {
            steps {
                sh 'cmake .'
                sh 'make'
            }
        }

        stage('Test') {
            steps {
                sh './test_calculator'
            }
        }

        stage('Docker Build & Push') {
            steps {
                sh 'docker build -t ishtiyak3000/spe_calculator .'
                sh 'docker login -u $DOCKERHUB_USER -p $DOCKERHUB_PASS'
                sh 'docker push ishtiyak3000/spe_calculator'
            }
        }

        stage('Deploy with Ansible') {
            steps {
                sh 'ansible-playbook -i inventory playbook.yml'
            }
        }
    }
}
