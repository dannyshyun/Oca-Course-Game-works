Get-ChildItem *.fbx -Filter "*Jack*" | ForEach 
{
    Get-ChildItem -Filter "*Jack*" | ForEach
    {

    }
    Rename-Item $_ -NewName $_.Name.Replace("Jack", "1")
}
Get-ChildItem *.fbx -Filter "*Queen*" | ForEach 
{
    Rename-Item $_ -NewName $_.Name.Replace("Queen", "2")
}
Get-ChildItem *.fbx -Filter "*King*" | ForEach 
{
    Rename-Item $_ -NewName $_.Name.Replace("King", "3")
}
Get-ChildItem *.fbx -Filter "*Card_Spade*" | ForEach 
{
    Rename-Item $_ -NewName $_.Name.Replace("Card_Spade", "Sword")
}
Get-ChildItem *.fbx -Filter "*Ace*" | ForEach 
{
    Rename-Item $_ -NewName $_.Name.Replace("Ace", "1")
}