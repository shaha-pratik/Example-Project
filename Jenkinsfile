def sendFailureStatusByEmail() {
    echo 'Notifying user regarding build failure'
    wrap([$class: 'BuildUser']) {
        def isStartedByUser = currentBuild.rawBuild.getCause(hudson.model.Cause$UserIdCause) != null
        if (isStartedByUser) {
            jobUserEmail = "${BUILD_USER_EMAIL}"
        } else {
            sh 'git log --format="%ae" | head -1 > commit-author.txt'
            jobUserEmail = readFile('commit-author.txt').trim()
        }
    }
    emailext (
            attachLog: true,
            subject: "${currentBuild.result} - Pipeline ${env.JOB_NAME} for Build# ${env.BUILD_NUMBER}",
            body: """
                    You can find the complete details below:
                    Pipeline name : ${env.JOB_NAME}
                    Result : ${currentBuild.result}
                    MR title : ${env.BRANCH_NAME}
                    Build number : ${env.BUILD_NUMBER}
                    Build Url : ${env.BUILD_URL}
                    Total Duration(in ms) : ${currentBuild.duration}

                    Please check for the cause of problem in the attached logs.
                    """,
            to:  "${jobUserEmail}",
            from: 'jenkins@swf.daimler.com'
        )
}


node ( ) {
    try {
        stage('Checkout') {
            checkout scm
        }

        stage('Docker') {
            dockerImage = docker.build("example-project", ".")
        }

        stage('code format') {
            dockerImage.inside("-u 0:0") {
                // sh 'pre-commit run'
            }
        }

        stage('Build')
        {
            dockerImage.inside("-u 0:0") {
                sh './build.sh'
            }
        }

        stage('Test')
        {
            dockerImage.inside("-u 0:0") {
                sh './test.sh'
            }
        }


    }
    catch (e) {
        currentBuild.result = 'FAILURE'
        sendFailureStatusByEmail()
        throw e
    }
    finally {
        stage('Cleanup') {
            step([$class: 'WsCleanup'])
        } // stage
    }
}
