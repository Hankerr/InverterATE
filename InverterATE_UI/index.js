const {
    app,
    BrowserWindow,
    ipcMain,
    Tray,
    Menu,
    screen,
    dialog
} = require('electron')
const path = require('path')

let mainWindow

// 应用程序单实例
if (app.requestSingleInstanceLock()) { // 判断是否自由一个实例
    app.on('second-instance', (event, commandLine, workingDirectory) => {
        let allWin = BrowserWindow.getAllWindows()
        allWin.map(win => {
            win.show()
        })
    })
} else { // 关闭当前新创建的实例
    app.quit()
}


const iconPath = path.join(__dirname, './src/img/icon.png')

app.on('ready', () => {

    mainWindow = new BrowserWindow({
        frame: false,
        resizable: false,
        width: 800,
        height: 600,
        icon: iconPath,
        webPreferences: {
            backgroundThrottling: false,
            nodeIntegration: true,
            contextIsolation: false
            // preload: path.join(__dirname, './preload.js')
        }
    })

    mainWindow.loadURL(`file://${__dirname}/src/main.html`)
})

app.on('activate', () => {
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
})
