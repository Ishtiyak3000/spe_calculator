pipeline {
    agent any

    environment {
        DOCKERHUB_CRED = credentials('DockerHubCred')
    }
     

    stages {
      
        
        stage('Checkout') {
            steps {
                git branch: 'main', url: 'https://github.com/ishtiyak3000/spe_calculator.git'
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
                sh 'echo $DOCKERHUB_CRED_PSW | docker login -u $DOCKERHUB_CRED_USR --password-stdin'
                sh 'docker push ishtiyak3000/spe_calculator'
            }
        }

        stage('Deploy with Ansible') {
            environment {
                ANSIBLE_CRED = credentials('AnsibleCred')
            }
            steps {
                sh 'ansible-playbook -i inventory playbook.yml --extra-vars "ansible_user=$ANSIBLE_CRED_USR ansible_password=$ANSIBLE_CRED_PSW"'
            }
        }
    }
}


