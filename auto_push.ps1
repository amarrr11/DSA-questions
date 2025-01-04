# Configuration
$repoPath = "C:\path\to\your\repository" # Replace with your local repository path
$commitMessage = "Automated commit by PowerShell script"
$pushInterval = 10 # Interval in seconds

# Change directory to the repository
Set-Location $repoPath

Write-Host "Monitoring directory: $repoPath"

while ($true) {
    # Check for changes
    $status = git status --porcelain
    if ($status) {
        Write-Host "Changes detected. Committing and pushing..."
        git add .
        git commit -m $commitMessage
        git push
        Write-Host "Changes pushed successfully!"
    }
    # Wait before the next check
    Start-Sleep -Seconds $pushInterval
}
