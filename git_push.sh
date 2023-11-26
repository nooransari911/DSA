ssh -T git@github.com
git add .
git remote set-url origin git@github.com:nooransari911/DSA.git
echo "Enter commit message:"
read commit_message
git commit -m "$commit_message"
git push -u origin main
