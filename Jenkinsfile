// Имя выходного файла
def EXECUTABLE_FILE_NAME = "puzzle"

// Версия программы
def VERSION = ""

pipeline {
    agent any
    stages {
        stage('genqt') {
            steps {
                sh 'bash genqt.sh'
            }
        }

        stage('build') {
            steps {
                sh 'bash compile.sh'
            }
        }

        stage('cppcheck') {
            steps {
                sh 'cppcheck --enable=all --xml --xml-version=2 -i ext  src 2> build/cppcheck.xml'
                sh 'cppcheck-htmlreport --source-encoding="iso8859-1" --title="project" --source-dir=. --report-dir=build --file=build/cppcheck.xml'
                publishHTML(
                    target: [
                      allowMissing: true,
                      alwaysLinkToLastBuild: false,
                      keepAll: false,
                      reportDir: 'build',
                      reportFiles: 'index.html',
                      reportName: 'CppCheck Report',
                      reportTitles: ''
                    ]
                )
            }
        }

        stage('archive') {
            steps {
                script {
                    VERSION = sh( returnStdout: true, script: "build/${EXECUTABLE_FILE_NAME} -v" ).trim()
                    sh "zip build/${EXECUTABLE_FILE_NAME}-${VERSION}.zip build/${EXECUTABLE_FILE_NAME}.exe build/${EXECUTABLE_FILE_NAME}"
                }
            }
        }

        stage('artifacts') {
            steps {
                archiveArtifacts artifacts: "build/${EXECUTABLE_FILE_NAME}-${VERSION}.zip", onlyIfSuccessful: true
            }
        }

        stage('clean') {
            steps {
                cleanWs()
            }
        }
    }
    options {
        // Хранить только одну удачную сбороку
        buildDiscarder(logRotator(numToKeepStr: '1'))
    }
}
